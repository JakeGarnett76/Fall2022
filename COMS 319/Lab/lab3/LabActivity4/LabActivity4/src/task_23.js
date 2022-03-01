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
                    {this.props.menu_items.map(function(item){return <li key={item}>{item}</li>})}
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
                <h1>Intro to React</h1>
                <p>This is an intro to React</p>
            </article>
        );
    }
}

class Acomponent extends React.Component {
    render() {
        const divStyle = {
            color: 'green',
            textAlign: 'center',
        };
        return (<div>
            <p style={divStyle}> A simple react component with inline style</p>
        </div>);
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


// Start Coding here
class App extends React.Component{

        constructor(props){
            super(props);
            this.state = {
                menu_items : ['Introduction', 'Basics', 'Javascript']
            };
            this.handleAddItem = this.handleAddItem.bind(this);
        }
        

        handleAddItem(event){
            event.preventDefault();
            const new_item = event.target.elements.new_item.value.trim();

            if(!new_item){
                alert('Enter valid value to add item');
            }

            this.setState(function(prevState, props){
                return{
                    menu_items: prevState.menu_items.concat(new_item)
                };
            });
        }

        render(){
            return(
                <div>
                    <Header />
                    <Nav menu_items={this.state.menu_items} handleAddItem={this.handleAddItem}/>
                    <Article />
                    <Footer />
                    <Acomponent />
                </div>
            );
    }
}

ReactDOM.render(<App />, document.getElementById("app"));
