const form = document.getElementById("form");
const FirstName = document.getElementById("FirstName");
const LastName = document.getElementById("LastName");
const Phone = document.getElementById("Phone");
const Email = document.getElementById("Email");
const addContact = document.getElementById("addContactBtn");
addContact.addEventListener("click", (e) => {
  e.preventDefault();
  checkInputs();
});

function checkInputs() {
  var flag = 1;
  const FirstNameValue = FirstName.value.trim();
  const PhoneValue = Phone.value.trim();
  const EmailValue = Email.value.trim();

  if (FirstNameValue === "") {
    setErrorFor(FirstName, "First Name cannot be blank!");
    flag = 0;
  } else if (!isName(FirstNameValue)) {
    setErrorFor(FirstName, "Enter a valid name!");
    flag = 0;
  } else {
    setSuccessFor(FirstName);
  }

  if (EmailValue === "") {
    setErrorFor(Email, "Email cannot be blank!");
    flag = 0;
  } else if (!isEmail(EmailValue)) {
    setErrorFor(Email, "Invalid Email!");
    flag = 0;
  } else {
    setSuccessFor(Email);
  }

  if (PhoneValue === "") {
    setErrorFor(Phone, "Number cannot be blank!");
    flag = 0;
  } else if (!isPhone(PhoneValue)) {
    setErrorFor(Phone, "Invalid Phone Number!");
    flag = 0;
  } else {
    setSuccessFor(Phone);
  }

  if (flag === 1) {
    setErrorFor(addContact, "Contact Added Successfully!");
  }
}

function setErrorFor(input, message) {
  const formControl = input.parentElement;
  const small = formControl.querySelector("small");
  if (small != null) {
    small.innerText = message;
  }
  formControl.className = "input-grp error";
}

function setSuccessFor(input) {
  const formControl = input.parentElement;
  formControl.className = "input-grp success";
}

function isEmail(email) {
  return /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(
    email
  );
}
function isPhone(number) {
  return /^\+?([0-9]{2})\)?[-. ]?([0-9]{4})[-. ]?([0-9]{4})$/.test(number);
}

function isName(name) {
  return /^[A-Za-z]+$/.test(name);
}

//For displaying contacts

let filterInput = document.getElementById("filterInput");

filterInput.addEventListener("keyup", filterNames);

function filterNames() {
  let filterValue = document.getElementById("filterInput").value.toUpperCase();
  console.log(filterValue);

  let contactList = document.getElementById("contact-list");

  //Get First Names/Phone Numbers

  let Name = contactList.querySelectorAll("td.ite");
  let LName = contactList.querySelectorAll("td.lite");
  let Number = contactList.querySelectorAll("td.nume");

  for (let i = 0; i < Name.length; i++) {
    let FullName = Name[i].innerHTML + " " + LName[i].innerHTML;

    if (
      FullName.toUpperCase().indexOf(filterValue) > -1 ||
      Name[i].innerHTML.toUpperCase().indexOf(filterValue) > -1 ||
      Number[i].innerHTML.toUpperCase().indexOf(filterValue) > -1 ||
      LName[i].innerHTML.toUpperCase().indexOf(filterValue) > -1
    ) {
      Name[i].parentElement.style.display = "";
       
    } else {
      Name[i].parentElement.style.display = "none";
    }
  }
}
