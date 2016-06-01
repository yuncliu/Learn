class Add extends React.Component {
    constructor(props) {
        super(props);
        this.handleClick = (ev) => {
            let a = parseInt(this.refs.InputA.state.value);
            let b = parseInt(this.refs.InputB.state.value);
            console.log(a + b)
            console.log(ev.target)
        }
    }

    render() {
        return (
            <div>
            <Input ref="InputA" />
            <Input ref="InputB" />
            <p><input type="button" value="=" onClick={this.handleClick} /></p>
            </div>
        );
    }
}

class Input extends React.Component {
    constructor(props) {
        super(props);
        this.state={value : 0}
        this.handleChange = (ev) => {
            this.setState({value: ev.target.value});
        }
    }

    render() {
        return (<input type="text" value={this.state.value} onChange={this.handleChange} />);
    }
}


ReactDOM.render( <Add />, document.getElementById('react_add'));
