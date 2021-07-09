const MyObject = require("../build/ObjectWrap").MyObject


test("Wrap Object", () => {
    let obj = new MyObject(21);
    obj.plusOne(12);
    obj.multiply(2);
    expect(obj.getValue()).toEqual(66)
    expect(() => obj.plusOne()).toThrowError("Wrong number of arguments")
})
