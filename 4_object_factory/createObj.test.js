var addon = require("../build/ObjectFactory")

test("ObjectFactory", () => {
    expect(addon.createObject("Tom")).toEqual({
        id: 0,
        name: "Tom"
    })
    expect(addon.createObject("Jerry")).toEqual({
        id: 1,
        name: "Jerry"
    })
})
