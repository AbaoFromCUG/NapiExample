var addon = require("../build/FunctionArguments")

test("Add", () => {
    expect(addon.add(12, 13)).toEqual(25)
    expect(() => addon.add(13)).toThrow("Wrong number of arguments")
    expect(() => addon.add("13", 12)).toThrow("Wrong arguments")
})
