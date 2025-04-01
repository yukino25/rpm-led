var SerialPort = require('serialport');
var { ReadlineParser } = require('@serialport/parser-readline');


const parser = new ReadlineParser({
    delimiter: '\r\n'
});

var port = new SerialPort('COM6',{
    baudRate: 9600,
    dataBits: 8,
    parity: 'none',
    stopBits: 1,
    flowControl: false,
});

port.pipe(parser);
let i = 0;
setTimeout(function(){
    while (i < 1000){
        port.write("2000");
        i++;
    }
}, 3000);
