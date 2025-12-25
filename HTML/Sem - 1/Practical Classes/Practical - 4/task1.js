var arr = [];
function actionLog() {
    var count = -1;
    return function (a) {
        arr.push(a);
        for (let i = 0; i < count; i++) {
            console.log(a[i]);
        }
        count++;
        return arr;
    };
}

const input = actionLog();
console.log(input("walk"));
console.log(input("swim"));
