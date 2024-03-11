
function mul2(n) {
    return n*2;
}

function make_handler(span){
    return () => {
        span.innerHTML = mul2(myinput.value)
    }
}