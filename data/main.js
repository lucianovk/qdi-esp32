var slider1 = document.getElementById("servo1Slider");
var servo1P = document.getElementById("servo1P");
var temperature1P = document.getElementById("temperature1P");
var humidity1P = document.getElementById("humidity1P");

servo1P.innerHTML = slider1.value;
slider1.oninput = function () { slider1.value = this.value; servo1P.innerHTML = this.value; }

function getParam(param, value) {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', "/?" + param + "=" + value, true);
    xhr.send();
}

const getJSON = async url => {
    const response = await fetch(url);
    if (!response.ok) // check if response worked (no 404 errors etc...)
        throw new Error(response.statusText);

    const data = response.json(); // get JSON from the response
    return data; // returns a promise, which resolves to this data value
}

function readSensor() {
    getJSON("/sensor").then(data => {
        temperature1P.innerHTML=data["temp"].toFixed(2)+" ºC";
        humidity1P.innerHTML=data["hum"].toFixed(2)+" %";
        console.log(data);
    }).catch(error => {
        console.error(error);
    });
}