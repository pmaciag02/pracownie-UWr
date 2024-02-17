var p = {
    name: 'jan'
}

var q = {
    surname: 'kowalski'
}

Object.setPrototypeOf( p, q );
console.log( p.name );
console.log( p.surname );


function checkIfPropertyExists(obj, propName) {
    return obj.hasOwnProperty(propName);
  }
  
function checkIfPropertyExistsInPrototypeChain(obj, propName) {
    return propName in obj;
}
  


function enumerateOwnProperties(obj) {
    for (let prop in obj) {
      if (obj.hasOwnProperty(prop)) {
        console.log(prop);
      }
    }
  }

  
  function enumerateAllProperties(obj) {
    for (let prop in obj) {
        if (obj.hasOwnProperty(prop)) {
            console.log(prop);
          }
    }
  
    let proto = Object.getPrototypeOf(obj);
    while (proto) {
      for (let prop in proto) {
        console.log(prop);
      }
      proto = Object.getPrototypeOf(proto);
    }
  }



  function getLastProto2(o) {
    var t = o;
    do {
        for (let prop in t) {
            if (t.hasOwnProperty(prop)) {
                console.log(prop);
              }
        }
        o = t;
        t = Object.getPrototypeOf(o);
    } while (t);
    return o;
}
  

  
console.log(checkIfPropertyExists(p, 'name')); // true
console.log(checkIfPropertyExists(p, 'surname')); // false
  
console.log(checkIfPropertyExistsInPrototypeChain(p, 'name')); // true
console.log(checkIfPropertyExistsInPrototypeChain(p, 'surname')); // true
  

// enumerateOwnProperties(p)
// enumerateAllProperties(p)
getLastProto2(p)