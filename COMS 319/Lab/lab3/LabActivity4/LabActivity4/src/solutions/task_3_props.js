
class App extends React.Component{

    render(){
        const menu_items = ['Introduction', 'Basics', 'JavaScript', 'test'];
        return(
            <div>
            <Header />
            <Nav menu_items={menu_items}/>
            <Article />
            <Footer />
            </div>
        );
    }
}

class Header extends React.Component{
    render(){
        return(
            <header>
                <h2>CS 319</h2>
            </header>
        );
    }
}

class Nav extends React.Component {
    render(){
        return(
            <nav>
                <ul>
                {this.props.menu_items.map(function(item){return <li key={item}>{item}</li>})}
                </ul>
            </nav>
        );
    }
}

class Article extends React.Component {
    render(){
        return(
            <article>
                <h1>Intro to JavaScript</h1>
                <p>This is an intro to javascript</p>
            </article>
        );
    }
}

class Footer extends React.Component {
    render(){
        return(
            <footer>
                <p>Class of 2020</p>
            </footer>
        );
    }
}

ReactDOM.render(<App />, document.getElementById("app"));


