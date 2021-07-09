var addon = require("../build/Callbacks")

test("callback", (done) => {
    addon.runCallback((content) => {
        expect(content).toEqual("Hello Callback")
        done()
    })
})
