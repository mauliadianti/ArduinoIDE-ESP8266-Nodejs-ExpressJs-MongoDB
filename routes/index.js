var express = require('express');
var router = express.Router();
const data = require('../models/data');

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'to Mongo' });
});

router.post("/adddata", (req,res) => {
  const {number, hum, temp} = req.body;
  let errors = [];

  if(!number || !hum || !temp){
    errors.push({msg: "gaada data"});
  }
  if(errors.length>0){
    res.json({Message : errors})
  }else{
    const newdata = new data({
      number,
      hum,
      temp
    });

    newdata
    .save()
    .then(newdata => {
      res.json({Message: "data masuk"});
  })
  .catch(err => console.log(err));
  }
});
module.exports = router;

router.get("/getdata/:number", (req,res) => {
  var number = req.params.number;
  console.log(number);

  data.find({number: number}).exec((err, number)=> {
    console.log(number);
    res.json(number);
  });
})

/* nerimanya data ky gini
{
  "number" : "112233445566",
  "hum" : "70",
  "temp" : "30"
}
*/
