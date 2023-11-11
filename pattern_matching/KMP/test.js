const fs = require("fs")

let array = []

for(let i=0;i<100005;i++) {
    let a = Math.floor(Math.random()*26+65)
    array.push(a)
}

let str = String.fromCharCode(...array)


str += "\n\n"
str +="ABCABCD"

fs.writeFileSync("./KMP.in", str)