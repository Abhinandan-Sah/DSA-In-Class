const express= require("express")
const app= express();
const cors = require("cors")
const authRouter= require("./routers/authRouter.js")
require("dotenv").config();
const PORT = process.env.PORT||8080;
require('./models/dbConnection.js')

app.use(cors());
app.use(express.json()); // to parse JSON bodies
app.use(express.urlencoded({ extended: true })); // to parse URL-encoded bodies

app.use('/auth', authRouter);

app.listen(PORT, ()=>{
    console.log(`Server is running at Port ${PORT}`);
})