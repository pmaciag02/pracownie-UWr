var suma = 4;

var lista = document.getElementsByTagName("LI");
var i;
for (i = 0; i < lista.length; i++) {
    let dziecko = {front: document.createElement("div"), zrobione: 0};
    let tekst = document.createTextNode("Zrobione");
    dziecko.front.className = "done";
    dziecko.front.appendChild(tekst);
    dziecko.front.addEventListener('click', function(ev) {
      ev.target.parentElement.classList.toggle('checked');
      if(ev.target.parentElement.checked == 1) {
          suma = suma + 1;
          ev.target.parentElement.checked = 0
        } else {
          suma = suma - 1;
          ev.target.parentElement.checked = 1
        }
        document.getElementById("suma").innerHTML = "Pozostało: " + suma;
      
    }, false);
  lista[i].appendChild(dziecko.front);
  dziecko = document.createElement("div");
  tekst = document.createTextNode("Usuń");
  dziecko.className = "close";
  dziecko.appendChild(tekst);
  lista[i].appendChild(dziecko);
  // dziecko.onclick = function() {
  //   lista[i].style.display = "none";
  //   if(lista[i].checked == 1) {
  //     // suma = suma + 1;
  //     lista[i].checked = 0
  //   } else {
  //     suma = suma - 1;
  //     lista[i].checked = 1
  //     document.getElementById("suma").innerHTML = "Pozostało: " + suma;
  //   }
  //   // document.getElementById("suma").innerHTML = "Pozostało: " + suma;
  
  // }
}


var close = document.getElementsByClassName("close");
var i;
for (i = 0; i < close.length; i++) {
  close[i].onclick = function() {
    var div = this.parentElement;
    div.style.display = "none";

    if(div.checked == 1) {
      // suma = suma + 1;
      div.checked = 0
    } else {
      suma = suma - 1;
      div.checked = 1
    }
    document.getElementById("suma").innerHTML = "Pozostało: " + suma;
  
  }
}





function newElement() {
    suma++;
    document.getElementById("suma").innerHTML = "Pozostało: " + suma;
  var li = document.createElement("li");
  var inputValue = document.getElementById("input").value;
  var t = document.createTextNode(inputValue);
  li.appendChild(t);
  if (inputValue === '') {
    alert("Podaj planowaną aktywność!");
  } else {
    document.getElementById("ul").appendChild(li);
  }
  document.getElementById("input").value = "";

  let dziecko = {front: document.createElement("div"), zrobione: 0};
  let tekst = document.createTextNode("Zrobione");
  dziecko.front.className = "done";
  dziecko.front.appendChild(tekst);
  dziecko.front.addEventListener('click', function(ev) {
    ev.target.parentElement.classList.toggle('checked');
    if(ev.target.parentElement.checked == 1) {
        suma = suma + 1;
        ev.target.parentElement.checked = 0
      } else {
        suma = suma - 1;
        ev.target.parentElement.checked = 1
      }
      document.getElementById("suma").innerHTML = "Pozostało: " + suma;
    
  }, false);
  li.appendChild(dziecko.front);
  dziecko = document.createElement("div");
  tekst = document.createTextNode("Usuń");
  dziecko.className = "close";
  dziecko.appendChild(tekst);
  li.appendChild(dziecko);

  dziecko.onclick = function() {
    li.style.display = "none";
    if(li.checked == 1) {
      // suma = suma + 1;
      // li.checked = 0
    } else {
      suma = suma - 1;
      li.checked = 1
      document.getElementById("suma").innerHTML = "Pozostało: " + suma;
    }
    // document.getElementById("suma").innerHTML = "Pozostało: " + suma;
  
  }
} 
