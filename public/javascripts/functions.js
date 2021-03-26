let coba;
function getnumberdata(){
    var data = document.getElementById('data').value;
    var settings = {
        "url": "http://ca62ef1f5b9e.ngrok.io/getdata/"+data,
        "method": "GET",
        "timeout": 0,
      };
      
      $.ajax(settings).done(function (response) {
        console.log(response);
      });
}
