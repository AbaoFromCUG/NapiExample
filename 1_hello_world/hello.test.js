var addon = require('../build/HelloWorld')

test("Hello", () => {
    const content = addon.hello();
    expect(content).toEqual("Hello World")
})
