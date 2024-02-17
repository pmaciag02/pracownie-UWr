var __extends = (this && this.__extends) || (function () {
    var extendStatics = function (d, b) {
        extendStatics = Object.setPrototypeOf ||
            ({ __proto__: [] } instanceof Array && function (d, b) { d.__proto__ = b; }) ||
            function (d, b) { for (var p in b) if (Object.prototype.hasOwnProperty.call(b, p)) d[p] = b[p]; };
        return extendStatics(d, b);
    };
    return function (d, b) {
        if (typeof b !== "function" && b !== null)
            throw new TypeError("Class extends value " + String(b) + " is not a constructor or null");
        extendStatics(d, b);
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
})();
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (g && (g = 0, op[0] && (_ = 0)), _) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var __read = (this && this.__read) || function (o, n) {
    var m = typeof Symbol === "function" && o[Symbol.iterator];
    if (!m) return o;
    var i = m.call(o), r, ar = [], e;
    try {
        while ((n === void 0 || n-- > 0) && !(r = i.next()).done) ar.push(r.value);
    }
    catch (error) { e = { error: error }; }
    finally {
        try {
            if (r && !r.done && (m = i["return"])) m.call(i);
        }
        finally { if (e) throw e.error; }
    }
    return ar;
};
var _this = this;
var Endpoints;
(function (Endpoints) {
    Endpoints["ELIXIRS"] = "Elixirs";
    Endpoints["SPELLS"] = "Spells";
    Endpoints["HOUSES"] = "Houses";
    Endpoints["INGREDIENTS"] = "Ingredients";
    Endpoints["WIZARDS"] = "Wizards";
})(Endpoints || (Endpoints = {}));
;
var Objects;
(function (Objects) {
    Objects[Objects["ELIXIRS"] = 0] = "ELIXIRS";
    Objects[Objects["SPELLS"] = 1] = "SPELLS";
    Objects[Objects["HOUSES"] = 2] = "HOUSES";
    Objects[Objects["INGREDIENTS"] = 3] = "INGREDIENTS";
    Objects[Objects["WIZARDS"] = 4] = "WIZARDS";
})(Objects || (Objects = {}));
;
var DIFFICULTIES = ['easy', 'medium', 'hard'];
var TYPES = ['attack', 'defence', 'utility'];
var LIGHTS = ['dark', 'light'];
var elixirs;
var spells;
var FetchError = /** @class */ (function (_super) {
    __extends(FetchError, _super);
    function FetchError(response) {
        var _this = this;
        if (typeof response === "number") {
            _this = _super.call(this, "Error code: ".concat(response)) || this;
        }
        else {
            _this = _super.call(this, response) || this;
        }
        return _this;
    }
    return FetchError;
}(Error));
var fetchData = function (endpoint) { return __awaiter(_this, void 0, void 0, function () {
    var response, e_1;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0:
                _a.trys.push([0, 2, , 3]);
                return [4 /*yield*/, fetch("https://wizard-world-api.herokuapp.com/".concat(endpoint), {
                        method: "GET",
                        headers: {
                            "Content-Type": "application/json"
                        }
                    })];
            case 1:
                response = _a.sent();
                if (response.ok === false) {
                    throw new FetchError(response.status);
                }
                return [2 /*return*/, response.json()];
            case 2:
                e_1 = _a.sent();
                if (e_1 instanceof TypeError && e_1.message.includes("NetworkError")) {
                    throw new FetchError(e_1.message);
                }
                throw e_1;
            case 3: return [2 /*return*/];
        }
    });
}); };
var getElixirs = function () { return __awaiter(_this, void 0, void 0, function () {
    var data;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0: return [4 /*yield*/, fetchData(Endpoints.ELIXIRS)];
            case 1:
                data = _a.sent();
                return [2 /*return*/, data.filter(function (_a) {
                        var name = _a.name, effect = _a.effect;
                        return (name === null || name === void 0 ? void 0 : name.length) > 0 && (effect === null || effect === void 0 ? void 0 : effect.length) > 0;
                    })];
        }
    });
}); };
var getSpells = function () { return __awaiter(_this, void 0, void 0, function () {
    var data;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0: return [4 /*yield*/, fetchData(Endpoints.SPELLS)];
            case 1:
                data = _a.sent();
                return [2 /*return*/, data.filter(function (_a) {
                        var name = _a.name, incantation = _a.incantation;
                        return (name === null || name === void 0 ? void 0 : name.length) > 0 && (incantation === null || incantation === void 0 ? void 0 : incantation.length) > 0;
                    })];
        }
    });
}); };
var getRandomNumber = function (maxNumber) { return Math.floor(Math.random() * maxNumber); };
var getThreeOptions = function (objects) {
    var set = new Set();
    while (set.size < 3) {
        set.add(getRandomNumber(objects.length));
    }
    var _a = __read(set, 3), first = _a[0], second = _a[1], third = _a[2];
    return {
        option1: objects[first],
        option2: objects[second],
        option3: objects[third]
    };
};
var generateGame = function (options, questionFunction) {
    var valid = getRandomNumber(3);
    console.log("Cheatmode: Valid option is option ".concat(valid + 1));
    document.getElementById("question").innerText = questionFunction(options[valid].question);
    document.getElementById("option1").innerText = options[0].answer;
    document.getElementById("option2").innerText = options[1].answer;
    document.getElementById("option3").innerText = options[2].answer;
    document.getElementById("options").addEventListener("click", function (e) {
        var target = e.target;
        if (target.tagName !== "BUTTON")
            return;
        if (Number(target.dataset.option) === valid) {
            document.getElementById("response").innerText = "Good!";
            round();
            return;
        }
        document.getElementById("response").innerText = "Wrong!";
    });
};
var round = function () {
    var game = getRandomNumber(2);
    var optionsElement = "\n    <div id=\"options\">\n      <button id=\"option1\" data-option=\"0\"></button>\n      <button id=\"option2\" data-option=\"1\"></button>\n      <button id=\"option3\" data-option=\"2\"></button>\n    </div>\n  ";
    document.getElementById("game").innerHTML = optionsElement;
    if (game === Objects.ELIXIRS) {
        var _a = getThreeOptions(elixirs), option1 = _a.option1, option2 = _a.option2, option3 = _a.option3;
        var options = [option1, option2, option3].map(function (option) { return ({
            question: option.name,
            answer: option.effect
        }); });
        generateGame(options, function (question) { return "Elixir ".concat(question, " has effect:"); });
    }
    if (game === Objects.SPELLS) {
        var _b = getThreeOptions(spells), option1 = _b.option1, option2 = _b.option2, option3 = _b.option3;
        var options = [option1, option2, option3].map(function (option) { return ({
            question: option.name,
            answer: option.incantation
        }); });
        generateGame(options, function (question) { return "Spell ".concat(question, " has incantation:"); });
    }
};
var game = function () { return __awaiter(_this, void 0, void 0, function () {
    var e_2;
    var _a;
    return __generator(this, function (_b) {
        switch (_b.label) {
            case 0:
                _b.trys.push([0, 2, , 3]);
                return [4 /*yield*/, Promise.all([getElixirs(), getSpells()])];
            case 1:
                _a = __read.apply(void 0, [_b.sent(), 2]), elixirs = _a[0], spells = _a[1];
                round();
                return [3 /*break*/, 3];
            case 2:
                e_2 = _b.sent();
                document.getElementById("game").innerHTML = "";
                document.getElementById("question").innerHTML = "";
                if (e_2 instanceof FetchError) {
                    document.getElementById("response").innerText =
                        "Problem with the connection. Try refreshing the page.";
                    return [2 /*return*/];
                }
                document.getElementById("response").innerText = e_2.message;
                return [3 /*break*/, 3];
            case 3: return [2 /*return*/];
        }
    });
}); };
function isSpell(object) {
    return 'incantation' in object;
}
function isElixir(object) {
    return 'sideEffects' in object;
}
game();
var check = function (object) {
    if (isSpell(object)) {
        console.log(object.incantation);
    }
    if (isElixir(object)) {
        console.log(object.ingredients);
    }
};
