const router = require('express').Router()
const {googleLogin, signin, signup} = require('../controllers/authController');

router.get('/test', (req, res)=>{
    res.send('test pass');
});
router.get('/google', googleLogin)
router.post('/signin', signin);
router.post('/signup', signup);

module.exports=router;