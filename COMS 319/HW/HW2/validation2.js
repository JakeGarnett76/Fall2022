
function validateForm2() {
  validate = 0;

  validateEmail();
  validatePhone();
  validateAddress();

  if(validate == 3){
    alert("yeet");
  }
}

function validateEmail(){
  var correctImage = new Image(15,15);
  correctImage.src = "./correct.png"

  var incorrectImage = new Image(15,15);
  incorrectImage.src = "./wrong.png"

  let email = document.forms["myForm"]["email"].value;
  var check = 0;
  for(let x = 0; x < email.length; x++){
    if(email[x] == '@'){
      check++;
    }
  }

  if(check == 0){
    document.getElementById('email1').appendChild(incorrectImage);
  }
  if(check == 1){
    document.getElementById('email1').appendChild(correctImage);
    validate++;
  }
}


function validatePhone(){
  var correctImage = new Image(15,15);
  correctImage.src = "./correct.png"

  var incorrectImage = new Image(15,15);
  incorrectImage.src = "./wrong.png"

  var phone = document.forms["myForm"]["phone"].value;
  var dash = 0;
  for(let y = 0; y < phone.length; y++){
    if(phone[y] == '-'){
      dash++;
    }
  }
  if(dash == 2 || dash == 0 && phone.length > 0){
    document.getElementById('phone1').appendChild(correctImage);
    validate++;
  }
  if(dash != 2 && dash != 0){
    document.getElementById('phone1').appendChild(incorrectImage);
  }
}

function validateAddress(){
  var correctImage = new Image(15,15);
  correctImage.src = "./correct.png"

  var incorrectImage = new Image(15,15);
  incorrectImage.src = "./wrong.png"

  var address = document.forms["myForm"]["address"].value;
  
  var addy = 0;
  for(let y = 0; y < address.length; y++){
    if(phone[y] == ','){
      addy = addy + 1;
    }
  }
  if(addy == 2){
    document.getElementById('address1').appendChild(correctImage);
    validate++;
  }
  if(addy != 2){
    document.getElementById('address1').appendChild(incorrectImage);
  }
}