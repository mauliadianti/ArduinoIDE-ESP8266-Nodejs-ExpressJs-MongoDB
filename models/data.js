const mongoose = require("mongoose");
const dataSchema = new mongoose.Schema({
    number : {
        type: String,
        required: true
    },
    hum: {
        type: String,
        required: true
    },
    temp: {
        type: String,
        required: true
    },
    updatedate: {
        type: Date,
        default: Date.now(),
        required: false
    }
});

const datasensor = mongoose.model("datasensor", dataSchema);

module.exports = datasensor;