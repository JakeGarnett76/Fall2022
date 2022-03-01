"use strict";

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } }

function _possibleConstructorReturn(self, call) { if (!self) { throw new ReferenceError("this hasn't been initialised - super() hasn't been called"); } return call && (typeof call === "object" || typeof call === "function") ? call : self; }

function _inherits(subClass, superClass) { if (typeof superClass !== "function" && superClass !== null) { throw new TypeError("Super expression must either be null or a function, not " + typeof superClass); } subClass.prototype = Object.create(superClass && superClass.prototype, { constructor: { value: subClass, enumerable: false, writable: true, configurable: true } }); if (superClass) Object.setPrototypeOf ? Object.setPrototypeOf(subClass, superClass) : subClass.__proto__ = superClass; }

var Header = function (_React$Component) {
    _inherits(Header, _React$Component);

    function Header() {
        _classCallCheck(this, Header);

        return _possibleConstructorReturn(this, (Header.__proto__ || Object.getPrototypeOf(Header)).apply(this, arguments));
    }

    _createClass(Header, [{
        key: "render",
        value: function render() {
            return React.createElement(
                "header",
                null,
                React.createElement(
                    "h2",
                    null,
                    "CS 319"
                )
            );
        }
    }]);

    return Header;
}(React.Component);

var Nav = function (_React$Component2) {
    _inherits(Nav, _React$Component2);

    function Nav() {
        _classCallCheck(this, Nav);

        return _possibleConstructorReturn(this, (Nav.__proto__ || Object.getPrototypeOf(Nav)).apply(this, arguments));
    }

    _createClass(Nav, [{
        key: "render",
        value: function render() {
            return React.createElement(
                "nav",
                null,
                React.createElement(
                    "ul",
                    null,
                    this.props.menu_items.map(function (item) {
                        return React.createElement(
                            "li",
                            { key: item },
                            item
                        );
                    })
                ),
                React.createElement(
                    "form",
                    { onSubmit: this.props.handleAddItem },
                    React.createElement("input", { type: "text", name: "new_item" }),
                    React.createElement(
                        "button",
                        null,
                        "Add item"
                    )
                )
            );
        }
    }]);

    return Nav;
}(React.Component);

var Article = function (_React$Component3) {
    _inherits(Article, _React$Component3);

    function Article() {
        _classCallCheck(this, Article);

        return _possibleConstructorReturn(this, (Article.__proto__ || Object.getPrototypeOf(Article)).apply(this, arguments));
    }

    _createClass(Article, [{
        key: "render",
        value: function render() {
            return React.createElement(
                "article",
                null,
                React.createElement(
                    "h1",
                    null,
                    "Intro to React"
                ),
                React.createElement(
                    "p",
                    null,
                    "This is an intro to React"
                )
            );
        }
    }]);

    return Article;
}(React.Component);

var Acomponent = function (_React$Component4) {
    _inherits(Acomponent, _React$Component4);

    function Acomponent() {
        _classCallCheck(this, Acomponent);

        return _possibleConstructorReturn(this, (Acomponent.__proto__ || Object.getPrototypeOf(Acomponent)).apply(this, arguments));
    }

    _createClass(Acomponent, [{
        key: "render",
        value: function render() {
            var divStyle = {
                color: 'green',
                textAlign: 'center'
            };
            return React.createElement(
                "div",
                null,
                React.createElement(
                    "p",
                    { style: divStyle },
                    " A simple react component with inline style"
                )
            );
        }
    }]);

    return Acomponent;
}(React.Component);

var Footer = function (_React$Component5) {
    _inherits(Footer, _React$Component5);

    function Footer() {
        _classCallCheck(this, Footer);

        return _possibleConstructorReturn(this, (Footer.__proto__ || Object.getPrototypeOf(Footer)).apply(this, arguments));
    }

    _createClass(Footer, [{
        key: "render",
        value: function render() {
            return React.createElement(
                "footer",
                null,
                React.createElement(
                    "p",
                    null,
                    "Class of 2020"
                )
            );
        }
    }]);

    return Footer;
}(React.Component);

// Start Coding here


var App = function (_React$Component6) {
    _inherits(App, _React$Component6);

    function App(props) {
        _classCallCheck(this, App);

        var _this6 = _possibleConstructorReturn(this, (App.__proto__ || Object.getPrototypeOf(App)).call(this, props));

        _this6.state = {
            menu_items: ['Introduction', 'Basics', 'Javascript']
        };
        _this6.handleAddItem = _this6.handleAddItem.bind(_this6);
        return _this6;
    }

    _createClass(App, [{
        key: "handleAddItem",
        value: function handleAddItem(event) {
            event.preventDefault();
            var new_item = event.target.elements.new_item.value.trim();

            if (!new_item) {
                alert('Enter valid value to add item');
            }

            this.setState(function (prevState, props) {
                return {
                    menu_items: prevState.menu_items.concat(new_item)
                };
            });
        }
    }, {
        key: "render",
        value: function render() {
            return React.createElement(
                "div",
                null,
                React.createElement(Header, null),
                React.createElement(Nav, { menu_items: this.state.menu_items, handleAddItem: this.handleAddItem }),
                React.createElement(Article, null),
                React.createElement(Footer, null),
                React.createElement(Acomponent, null)
            );
        }
    }]);

    return App;
}(React.Component);

ReactDOM.render(React.createElement(App, null), document.getElementById("app"));
