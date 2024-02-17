console.log((![]+[])[+[]]+(![]+[])[+!+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]);



// (![]+[])[+[]] === (false + [])[0] === 'false'[0] === 'f'
console.log( (![]+[])[+[]] === ('false' + [])[0] && ('false' + [])[0] === 'false'[0] && 'false'[0] === 'f' )

// (![]+[])[+!+[]] === 'false'[+ true] === 'false'[1] === 'a'
console.log( (![]+[])[+!+[]] === 'false'[+ true] && 'false'[+ true] === 'false'[1] && 'false'[1] === 'a' )

// ([![]]+[][[]])[+!+[]+[+[]]] === ([false] + undefined)[1 + [0]] === 'falseundefined'['10'] === 'i'
console.log( ([![]]+[][[]])[+!+[]+[+[]]] === ([false] + undefined)[1 + [0]] && ([false] + undefined)[1 + [0]] === 'falseundefined'['10'] && 'falseundefined'['10'] === 'i' )


// (![]+[])[!+[]+!+[]] === 'false'[true + true] === 'false'[2] === 'l'
console.log( (![]+[])[!+[]+!+[]] === 'false'[true + true] && 'false'[true + true] === 'false'[2] && 'false'[2] === 'l' )


// 'false'[0] + 'false'[1] + 'falseundefined'['10'] + 'false'[2] == 'f' + 'a' + 'i' + 'l' == 'fail'
