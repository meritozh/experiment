"use strict";
exports.__esModule = true;
var stream_1 = require("stream");
var rs = new stream_1.Readable;
var c = 97 - 1;
rs._read = function () {
    if (c >= 'z'.charCodeAt(0)) {
        return rs.push(null);
    }
    setTimeout(function () {
        rs.push(String.fromCharCode(++c));
    }, 100);
};
rs.pipe(process.stdout);
process.on('exit', function () {
    console.error('\n_read() called ' + (c - 97) + ' times');
});
process.stdout.on('error', process.exit);
