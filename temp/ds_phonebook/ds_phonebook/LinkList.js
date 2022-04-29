class Node {
  constructor(number, first_name, last_name, email) {
    this.number = number;
    this.first_name = first_name;
    this.last_name = last_name;
    this.email = email;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
    this.size = 0;
  }

  add(first_name, last_name, email, number) {
    var node = new Node(number, first_name, last_name, email);
    var current;

    if (this.head == null) this.head = node;
    else {
      current = this.head;

      while (current.next) {
        current = current.next;
      }
      current.next = node;
    }
    this.size++;
  }

  removeElement(number) {
    var current = this.head;
    var prev = null;
    while (current != null) {
      if (current.number === number) {
        if (prev == null) {
          this.head = current.next;
        } else {
          prev.next = current.next;
        }
        this.size--;
        return current.number;
      }
      prev = current;
      current = current.next;
    }
    return -1;
  }

  indexOf(number) {
    var count = 0;
    var current = this.head;
    while (current != null) {
      if (current.element === number) return count;
      count++;
      current = current.next;
    }
    return -1;
  }

  isEmpty() {
    return this.size == 0;
  }

  size_of_list() {
    console.log(this.size);
  }

  printList() {
    var curr = this.head;
    var str = "";
    while (curr) {
      str +=
        curr.first_name +
        " " +
        curr.last_name +
        " " +
        curr.email +
        " " +
        curr.number +
        "\n";
      curr = curr.next;
    }
    console.log(str);
  }
}

var ll = new LinkedList();

class Contact {
  constructor(FirstName, LastName, Phone, Email) {
    this.FirstName = FirstName;
    this.LastName = LastName;
    this.Phone = Phone;
    this.Email = Email;
  }
}

class UI {
  static displayContacts() {
    const Contacts = Store.getContacts();

    // Contacts.forEach((contact) => UI.addContactToList(contact));

    Contacts.forEach((contact) =>
      ll.add(contact.FirstName, contact.LastName, contact.Email, contact.Phone)
    );
    // ll.printList();

    var curr = ll.head;
    while (curr != null) {
      UI.addContactToList(curr);
      curr = curr.next;
    }
  }

  static addContactToList(curr) {
    const list = document.querySelector("#contact-list");
    const row = document.createElement("tr");
    row.innerHTML = `
    <td class="text-white ite">${curr.first_name}</td>
    <td class="text-white lite">${curr.last_name}</td>
    <td class="text-white nume">${curr.number}</td>
    <td class="text-white">${curr.email}</td>
    <td><a href="javascript:void();" class="btn btn-danger btn-sm delet">Delete</a></td>
    `;

    list.appendChild(row);
  }

  static deleteContact(el) {
    if (el.classList.contains("delet")) {
      el.parentElement.parentElement.remove();
    }
  }

  static clearFields() {
    document.querySelector("#FirstName").value = " ";
    document.querySelector("#LastName").value = " ";
    document.querySelector("#Phone").value = " ";
    document.querySelector("#Email").value = " ";
  }

  static setDefault(input) {
    const formControl = input.parentElement;
    formControl.className = "input-grp";
  }
}

//Storage Part
class Store {
  static getContacts() {
    let Contacts;
    if (localStorage.getItem("Contacts") === null) {
      Contacts = [];
    } else {
      Contacts = JSON.parse(localStorage.getItem("Contacts"));
    }
    return Contacts;
  }

  static addContact(contact) {
    const Contacts = Store.getContacts();
    Contacts.push(contact);
    localStorage.setItem("Contacts", JSON.stringify(Contacts));
    ll.add(contact.FirstName, contact.LastName, contact.Email, contact.Phone);
  }

  static removeContact(Email, Phone, LastName, FirstName) {
    const Contacts = Store.getContacts();
    Contacts.forEach((contact, index) => {
      if (
        contact.Email == Email &&
        contact.FirstName == FirstName &&
        contact.LastName == LastName &&
        contact.Phone == Phone
      ) {
        Contacts.splice(index, 1);
      }
    });

    localStorage.setItem("Contacts", JSON.stringify(Contacts));
  }
}

document.addEventListener("DOMContentLoaded", UI.displayContacts);

const addContactBtn = document.getElementById("addContactBtn");
addContact.addEventListener("click", (e) => {
  const FirstName = document.getElementById("FirstName").value;
  const LastName = document.getElementById("LastName").value;
  const Phone = document.getElementById("Phone").value;
  const Email = document.getElementById("Email").value;
  if (addContactBtn.parentElement.className === "input-grp error") {
    const contact = new Contact(FirstName, LastName, Phone, Email);
    var node = new Node(Phone, FirstName, LastName, Email);
    ll.add(FirstName, LastName, Phone, Email);
    UI.addContactToList(node);
    Store.addContact(contact);
    // console.log(contact);
    UI.clearFields();
    UI.setDefault(document.getElementById("FirstName"));
    UI.setDefault(document.getElementById("LastName"));
    UI.setDefault(document.getElementById("Phone"));
    UI.setDefault(document.getElementById("Email"));

    if (document.querySelector("#C_add_suu") != null) {
      setTimeout(
        () =>
          (document.querySelector("#C_add_suu").parentElement.className =
            "input-grp"),
        3000
      );
    }
  }
});

//Delete

document.querySelector("#contact-list").addEventListener("click", (e) => {
  //Remove from UI
  UI.deleteContact(e.target);

  //Remove from Storage
  Store.removeContact(
    e.target.parentElement.previousElementSibling.textContent,
    e.target.parentElement.previousElementSibling.previousElementSibling
      .textContent,
    e.target.parentElement.previousElementSibling.previousElementSibling
      .previousElementSibling.textContent,
    e.target.parentElement.previousElementSibling.previousElementSibling
      .previousElementSibling.previousElementSibling.textContent
  );
});

// Javascript program to implement Binary Search for strings
 
// Returns index of x if it is present in arr[],
// else return -1
function binarySearch(arr,x)
{
    let l = 0, r = arr.length - 1;
        while (l <= r) {
            let m = l + Math.floor((r - l) / 2);
   
            let res = x.localeCompare(arr[m]);
               
            // Check if x is present at mid
            if (res == 0)
                return m;
   
            // If x greater, ignore left half
            if (res > 0)
                l = m + 1;
   
            // If x is smaller, ignore right half
            else
                r = m - 1;
        }
   
        return -1;
}

