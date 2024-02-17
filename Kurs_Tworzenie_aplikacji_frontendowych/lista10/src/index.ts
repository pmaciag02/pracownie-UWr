import * as math from 'mathjs';
import './styles/main.scss'

const screen = document.getElementById('result') as HTMLInputElement;


function write(value:string) {
    if(value == "DEL") {
        screen.value=screen.value.substr(0, screen.value.length - 1);
    }
    else if(value == "CE") {
        screen.value = "0";
    }
    else if(screen.value == "0") {
        screen.value = value;
    }
    else {
        screen.value += value;
    }
}

document.querySelectorAll('.button').forEach(button => {
    button.addEventListener('click', () => write(button.innerHTML));
});




function evaluate(): number | string {
    try{
        return math.evaluate(screen.value);
    }
    catch(e){
        return "Error";
    }
}

document.getElementById("equal").addEventListener('click', () => screen.value=evaluate().toString());
