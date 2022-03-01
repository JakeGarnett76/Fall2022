
// const para = <p>This is a paragraph created with JSX.</p>;

// ReactDOM.render(para, document.getElementById("app"));



// const student = {
//     name: "Alex",
//     class: "CS 319",
//     year: 2020
// };


// const stud = (
//     <div>
//         <p>Student name: {student.name}</p>
//         <p>Class name: {student.class}</p>
//         <p>Year: {student.year}</p>
//     </div>
// );

// function App(){
//     return(
//         <div>
//             <h3>Class: CS319</h3>
//             <h3>Lab activity 4</h3>
//             <p>This is function component.</p>
//         </div>
//     );
// }

// ReactDOM.render(<App />, document.getElementById("app"));


// class App extends React.Component{
//     render(){
//         return(
//             <div>
//             <h3>Class: CS319</h3>
//             <h3>Lab activity 4</h3>
//             <p>This is function component.</p>
//         </div>
//         );
//     }
// }

// ReactDOM.render(<App />, document.getElementById("app"));


class App extends React.Component {
    constructor(props) {
        super(props);
        this.state = {
            menu_items: ['Introduction', 'Basics', 'JavaScript']
        };
        this.handleAddItem = this.handleAddItem.bind(this);
    }
    handleAddItem(event) {
        event.preventDefault();
        const new_item = event.target.elements.new_item.value.trim();

        if (!new_item) {
            alert('Enter valid value to add item');
        }

        this.setState(function (prevState, props) {
            return {
                menu_items: prevState.menu_items.concat(new_item)
            };
        });

    }

    render() {
        return (
            <div>
                <Header />
                <Nav menu_items={this.state.menu_items} handleAddItem={this.handleAddItem} />
                <Article />
                <Footer />
            </div>
        );
    }
}


class Header extends React.Component {
    render() {
        return (
            <header>
                <h2>CS 319</h2>
            </header>
        );
    }
}

class Nav extends React.Component {
    render() {
        return (
            <nav>
                <ul>
                    {this.props.menu_items.map(function (item) { return <li key={item}>{item}</li> })}
                </ul>
                <form onSubmit={this.props.handleAddItem}>
                    <input type="text" name="new_item" />
                    <button>Add item</button>
                </form>
            </nav>
        );
    }
}

class Article extends React.Component {
    render() {
        return (
            <article>
                <h1>Intro to JavaScript</h1>
                <p>This is an intro to javascript</p>
            </article>
        );
    }
}

class Footer extends React.Component {
    render() {
        return (
            <footer>
                <p>Class of 2020</p>
            </footer>
        );
    }
}

ReactDOM.render(<App />, document.getElementById("app"));


