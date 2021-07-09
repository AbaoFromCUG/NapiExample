const addon = require("../build/FactoryWrap");
const MyObject = require("../build/FactoryWrap").MyObject
const createWrapObject = require("../build/FactoryWrap").createWrapObject

test("Factory Wrap", ()=>{
    let obj = new MyObject(1);
    obj.plusOne(12);
    obj.multiply(2);

    expect(obj.getValue()).toEqual(26)

    let anotherObject = createWrapObject(14);
    anotherObject.multiply(2)
    anotherObject.plusOne(-2)
    expect(anotherObject.getValue()).toEqual(obj.getValue())
})

