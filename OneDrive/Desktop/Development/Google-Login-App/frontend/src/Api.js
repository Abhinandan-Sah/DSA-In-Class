import axios from "axios";

const api = axios.create({
  baseURL: "http://localhost:8080/auth",
});

export const googleAuth = async (code) => {
  console.log(code)
  const response = await api.get(`/google?code=${code}`);
  return response.data
};

export const signupAuth = async(data)=>{
  console.log("This is inside Api ", data)
  const response = await api.post("/signup", data);
  console.log(response?.data)
  return response?.data;
}

export const signinAuth = async(data)=>{
  const response = await api.post("/signin", data);
  return response?.data;
}
