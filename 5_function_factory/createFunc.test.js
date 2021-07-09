var addon = require("../build/FunctionFactory")


test("FunctionFactory", () => {
    const func = addon.createFunction("Tom");
    expect(func()).toEqual("Hello Tom")
})

