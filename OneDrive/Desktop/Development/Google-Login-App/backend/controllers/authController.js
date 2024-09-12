const axios = require("axios");
const { oauth2client } = require("../utils/googleConfig");
const UserModel = require("../models/userModel");
const jwt = require("jsonwebtoken");
const bcrypt = require("bcrypt");

const googleLogin = async (req, res) => {
  try {
    const { code } = req.query;
    const googleRes = await oauth2client.getToken({ code });
    oauth2client.setCredentials(googleRes.tokens);
    // console.log(googleRes.tokens.access_token);
    const userRes = await axios.get(
      `https://www.googleapis.com/oauth2/v3/userinfo?access_token=${googleRes.tokens.access_token}`
    );
    // console.log("userRes:   ", userRes)
    const { name, email, picture } = userRes?.data;
    let user = await UserModel.findOne({ email });
    if (!user) {
      user = await UserModel.create({
        name,
        email,
        image: picture,
      });
    }
    const { _id } = user;
    const token = jwt.sign({ _id, email }, process.env.JWT_SECRET, {
      expiresIn: process.env.JWT_TIMEOUT,
    });
    return res.status(200).json({
      success: true,
      message: "Success",
      token,
      user,
    });
  } catch (err) {
    res.status(500).json({
      success: false,
      message: "Internal server error",
    });
  }
};

const signin = async (req, res) => {
  const { email, password } = req.body;

  // Check if user exists
  const user = await UserModel.findOne({ email });
  if (!user) {
    return res.status(400).json({ success: false, message: "User not found" });
  }

  // Compare passwords
  const validPassword = await bcrypt.compare(password, user.password);
  if (!validPassword) {
    return res
      .status(400)
      .json({ success: false, message: "Invalid credentials" });
  }

  const { _id } = user;
  const token = jwt.sign({ _id, email }, process.env.JWT_SECRET, {
    expiresIn: process.env.JWT_TIMEOUT,
  });

  // Log in user (e.g., send JWT)
  res
    .status(200)
    .json({
      success: true,
      message: "User signed in successfully",
      user,
      token,
    });
};

const signup = async (req, res) => {
  console.log("hello from authcontroller")
  console.log("This is signup ",JSON.stringify(req.body))
  const { name, email, password } = req.body;

  // Check if user already exists
  const existingUser = await UserModel.findOne({ email });
  if (existingUser) {
    return res
      .status(400)
      .json({ success: false, message: "User already exists" });
  }

  // Hash password and create user
  const hashedPassword = await bcrypt.hash(password, 10);
  const user = await UserModel.create({
    name,
    email,
    password: hashedPassword,
  });

  console.log("user is created successfully")

  // await user.save();
  // res.status(201).json({ message: 'User registered successfully' });
  const { _id } = user;
  const token = jwt.sign({ _id, email }, process.env.JWT_SECRET, {
    expiresIn: process.env.JWT_TIMEOUT,
  });
  return res.status(200).json({
    success: true,
    message: "Success",
    token,
    user,
  });
};

module.exports = { googleLogin, signin, signup };
