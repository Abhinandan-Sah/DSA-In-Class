import { useRef, useState } from "react";
import { checkValidateData } from "./utils/validate";
import { signinAuth, signupAuth } from "./Api";
import { toast } from "react-toastify";
import { useNavigate } from "react-router-dom";

const Login = () => {
  

  const [isSignInForm, setIsSignInForm] = useState(true);

  // const [formData, setFormData] = useState({
  //     name: "",
  //     email: "",
  //     password: "",
  //   });

  const [errorMessage, setErrorMessage] = useState(null);

  const navigate = useNavigate();

  const Name = useRef(null);
  const Email = useRef(null);
  const Password = useRef(null);
  //if it is sign up form than show name

  const handleButtonClick = async (e) => {
    e.preventDefault();
    //Validate the Form Data
    const message = checkValidateData(
      isSignInForm ? null : Name.current.value.trim(),
      Email.current.value,
      Password.current.value
    );
    setErrorMessage(message);

    if (message) return; // if message is string which means it is not valid

    if (!isSignInForm) {
      // Sign Up Authentication
      const data = {
        name: Name.current.value,
        email: Email.current.value,
        password: Password.current.value,
      };
      console.log("Data -> ", data);
      const result = await signupAuth(data);
      console.log(result);

      const { name, email, image } = result.user;
      const { token } = result;
      const obj = { name, email, image, token };
      if (result.success === true) {
        toast.success(result.message);
        localStorage.setItem("user-info", JSON.stringify(obj));
        navigate("/dashboard");

        Email.current.value = "";
        Password.current.value = "";
        Name.current.value = "";
      } else {
        toast.error(result.message || "An error occurred during the process");
      }
    } else {
      // Sign In Authentication
      const data = {
        email: Email.current.value,
        password: Password.current.value,
      };
      const result = await signinAuth(data);
      console.log("Result is given below: ");
      console.log(result);
      // const Name= result?.user?.name;
      // const Email= result?.user?.email;
      // const Image= result?.user?.image;
      const { name, email, image } = result.user;
      console.log(name + email + image);
      const { token } = result;
      const obj = { name, email, image, token };
      if (result.success === true) {
        toast.success(result.message);
        localStorage.setItem("user-info", JSON.stringify(obj));
        navigate("/dashboard");

        //Resetting form
        Email.current.value = "";
        Password.current.value = "";
      } else {
        toast.error(result.message || "An error occurred during the process");
      }
    }
  };

  const toggleSignIn = () => {
    setIsSignInForm(!isSignInForm);
  };

  return (
    <div className="flex justify-center items-center flex-col w-full h-screen bg-gray-100">
      <div className=" bg-black w-1/2 flex justify-center items-center gap-3 h-16 rounded-t-lg">
        <img
          src="/Logo_Main.png"
          alt="login-img"
          className="w-10 rounded-md h-auto"
        />
        <h1 className="text-gray-100 text-xl font-bold">AgriPricePredictor</h1>
      </div>
      <div className={`w-1/2 h-[65%] flex shadow-lg rounded-lg ${isSignInForm? "w-1/2 h-[65%]" : "w-1/2 h-[70%]"}`}>
        <div className="hidden md:flex w-1/2 bg-green-100 items-center justify-center rounded-bl-lg">
          <img
            src="/Signin_logo.png"
            alt="login-img"
            className="w-4/5 rounded-md h-auto"
          />
        </div>
        <div className="flex flex-col justify-center w-full md:w-1/2 max-w-md mx-auto p-8  shadow-md rounded-br-lg">
          <form className="text-black ">
            <h1 className=" text-2xl text-black text-center font-bold p-2 mr-auto">
              {isSignInForm ? "Sign In" : "Sign Up"}
            </h1>
            {!isSignInForm && (
              <input
                ref={Name}
                type="text"
                placeholder="Full Name"
                className="w-full p-3 m-2 bg-slate-50 border border-black rounded-lg placeholder-gray-600 text-black"
              />
            )}
            <input
              ref={Email}
              type="email"
              placeholder="Email Address"
              className="w-full p-3 m-2 bg-slate-50 border border-black rounded-lg placeholder-gray-600 text-black"
            />
            <input
              ref={Password}
              type="password"
              placeholder="Password"
              className="w-full p-3 m-2 bg-slate-50 border border-black rounded-lg placeholder-gray-600 text-black"
            />
            <p className="text-red-500 font-bold text-sm m-2">{errorMessage}</p>
            <button
              onClick={handleButtonClick}
              className="p-2 m-2 w-full bg-green-600 rounded-lg text-gray-50 text-lg font-semibold"
            >
              {isSignInForm ? "Sign In" : "Sign Up"}
            </button>

            <p className="cursor-pointer pb-3 text-center" onClick={toggleSignIn}>
            {isSignInForm ? (
        <>
          <span>New to AgriPricePredictor? </span>
          <span style={{ color: 'blue', textDecoration: 'underline' }}>Sign Up Now</span>
        </>
      ) : (
        <>
          <span>Already registered? </span>
          <span style={{ color: 'blue', textDecoration: 'underline' }}>Sign In Now</span>
        </>
      )}
            </p>
            <div className="flex justify-center items-center flex-col mb-5">
            </div>
          </form>
        </div>
      </div>
    </div>
  );
};

export default Login;
