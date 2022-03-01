const form = document.getElementById('form')





function validateForm() {
  validate = 0;

  validateFirstName();
  validateLastName();
  validateGender();
  validateState();

  if(validate == 4){
    window.location.href = "./validation2.html";
  }

}

function validateLastName(){
    var correctImage = new Image(15,15);
    correctImage.src = "./correct.png"

    var incorrectImage = new Image(15,15);
    incorrectImage.src = "./wrong.png"

    var regex1 = /^[A-Za-z0-9]+$/
    var isValid1 = regex1.test(document.getElementById("lastName").value);
    if (isValid1 == false) {
      document.getElementById('lastName1').appendChild(incorrectImage);
    }
    if(isValid1 == true){
      document.getElementById('lastName1').appendChild(correctImage);
      validate++;
    }
}

function validateFirstName(){
    var correctImage = new Image(15,15);
    correctImage.src = "./correct.png"

    var incorrectImage = new Image(15,15);
    incorrectImage.src = "./wrong.png"


    var regex = /^[A-Za-z0-9]+$/
    var isValid = regex.test(document.getElementById("firstName").value);
    if (isValid == false) {
      document.getElementById('firstName1').appendChild(incorrectImage);
    }
    if(isValid == true){
      document.getElementById('firstName1').appendChild(correctImage);
      validate++;
    }
}

function validateGender(){
  var correctImage = new Image(15,15);
  correctImage.src = "./correct.png"

  var incorrectImage = new Image(15,15);
  incorrectImage.src = "./wrong.png"

  var gender = document.forms["myForm"]["gender"].value;
  if (gender == "") {
    document.getElementById('gender1').appendChild(incorrectImage);
  }

  if (gender != "") {
    document.getElementById('gender1').appendChild(correctImage);
    validate++;
  }
}

function validateState(){
  var correctImage = new Image(15,15);
  correctImage.src = "./correct.png"

  var incorrectImage = new Image(15,15);
  incorrectImage.src = "./wrong.png"


  var state = document.forms["myForm"]["state"].value;
  if (state == "") {
    document.getElementById('state1').appendChild(incorrectImage);
  }
  if (state != "") {
    document.getElementById('state1').appendChild(correctImage);
    validate++;
  }

}



