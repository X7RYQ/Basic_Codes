var fr = ["nous", "faisons", "un", "gateau"], eng = ["we", "make", "a", "cake"];
function Translation(W, lang = 'english') {
    let word = W.toLowerCase(), start, end;
    if (lang === 'english') {
        start = eng;
        end = fr;
    }
    else {
        start = fr;
        end = eng;
    }
    let position = start.indexOf(word);
    if (position !== -1) {
        return end[position];
    }
    else {
        return '?' + W + '?';
    }
}
console.log(Translation("cake"));
console.log(Translation("nous", "french"));

function sentence(sen, lang = 'french') {
    let transW = [], words = sen.split(' ');
    for (let i = 0; i < words.length; i++) {
        let str = words[i], last = " ";
        if ("?!.,-/".includes(str[str.length - 1])) {
            last = str[str.length - 1];
            str = str.slice(0, -1);
        }
        let trans = Translation(str, lang);
        transW.push(trans + last);
    }
    return transW.join(" ");
}
console.log(sentence("we make cake!", "english"));
