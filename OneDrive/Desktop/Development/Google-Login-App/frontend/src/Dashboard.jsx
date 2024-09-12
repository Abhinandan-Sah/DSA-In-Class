import { useEffect, useState } from "react";
import { useNavigate } from "react-router-dom";

const Dashboard = () => {
  const [userInfo, setUserInfo] = useState(null);

  const navigate = useNavigate();

  useEffect(()=>{
    fetchData();
  },[])

  const fetchData = async()=>{
    const data = localStorage.getItem('user-info');
    const json = JSON.parse(data);
    setUserInfo(json);
  }
  const handleSignout = (()=>{
    localStorage.removeItem('user-info');
    navigate("/login")
  })
  return (
    <div >
      <h1 className="text-2xl">
        Welcome {userInfo?.name}
      </h1>
      <h3 className="text-xl">
        {userInfo?.email}
      </h3>
      <div className="rounded-full"> 
        <img className="rounded-full" src={userInfo?.image} alt={userInfo?.name} />
      </div>
      <button className="border px-4 py-2 rounded-lg" onClick={handleSignout}>Sign Out</button>
    </div>
  )
}

export default Dashboard