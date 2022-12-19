var mqtt = require('mqtt');
const config = require("./../config");
//const fs = require('fs');

const MQTT_ENV = config.services.MQTT;

var options = {
    clientId: 'mqttj_' + Math.random().toString(16).substr(2, 8),
    rejectUnauthorized: true,
    username: MQTT_ENV.USERNAME,
    password: MQTT_ENV.PASSWORD,
    //key: fs.readFileSync("./certs/client.key"),
    //cert: fs.readFileSync("./certs/client.crt"),
    //ca: fs.readFileSync("./certs/ca.crt"),
    qos: 2,
    port: MQTT_ENV.PORT,
    //protocol: 'mqtts',
    clean: true
}

const URI = `mqtt://${MQTT_ENV.HOST}`;
console.log("MQTT:" +  URI);

const client = mqtt.connect( URI, options);
var arrayTopicsListen = [];
var arrayTopicsServer = [];
// connected
client.on('connect', function () {
    console.log("[MQTT] Init: Connected");
});
//handle errors
client.on("error", function (error) {
    console.log("[MQTT] Error: OCURRIÓ UN PROBLEMA: " + error);
    //console.log(options.ca);
});

client.MQTTOptions = options;
module.exports = client;