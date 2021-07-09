const MyObject = require("../build/PassingWrapped").MyObject
const createWrapObject = require("../build/PassingWrapped").createWrapObject
const addWrapObject = require("../build/PassingWrapped").addWrapObject

test("Passing Wrapped", () => {
    let obj1 = new MyObject(21);
    let obj2 = createWrapObject(12);
    let obj3 = addWrapObject(obj1, obj2)

    expect(obj3.getValue()).toEqual(33)
})
