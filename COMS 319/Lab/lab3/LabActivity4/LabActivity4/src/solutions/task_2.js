
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


class App extends React.Component{
    render(){
        return(
            <div>
            <h3>Class: CS319</h3>
            <h3>Lab activity 4</h3>
            <p>This is class component.</p>
        </div>
        );
    }
}

ReactDOM.render(<App />, document.getElementById("app"));

// class App extends React.Component{
//     render(){
//         return(
//             <div>
//             <Header />
//             <Nav />
//             <Article />
//             <Footer />
//             </div>
//         );
//     }
// }


// class Header extends React.Component{
//     render(){
//         return(
//             <header>
//                 <h2>CS 319</h2>
//             </header>
//         );
//     }
// }

// class Nav extends React.Component {
//     render(){
//         return(
//             <nav>
//                 <ul>
//                     <li>Introduction</li>
//                     <li>Basics</li>
//                     <li>JavaScript</li>
//                 </ul>
//             </nav>
//         );
//     }
// }

// class Article extends React.Component {
//     render(){
//         return(
//             <article>
//                 <h1>Intro to JavaScript</h1>
//                 <p>This is an intro to javascript</p>
//             </article>
//         );
//     }
// }

// class Footer extends React.Component {
//     render(){
//         return(
//             <footer>
//                 <p>Class of 2020</p>
//             </footer>
//         );
//     }
// }

// ReactDOM.render(<App />, document.getElementById("app"));


