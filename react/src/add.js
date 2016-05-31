class Add extends React.Component {
    handleClick(ev) {
        console.log(this.props.children)
    }
    render() {
        return (
                <div>
                <Input />
                <Input />
                <p><input type="button" value="=" onClick={ev=>this.handleClick(ev)} /></p>
                </div>
        );
    }
}

class Input extends React.Component {

    constructor(props) {
        super(props);
        this.state = {value : "Hellow"};
        //this.handleChange = this.handleChange.bind(this);
        this.handleChange = (ev) => {
            this.setState({value: ev.target.value});
        };
    }

    render() {
        return (<p><input type="text" value={this.state.value} onChange={this.handleChange} /></p>);
    }
/*
    handleChange(ev) {
        this.setState({value: ev.target.value});
    }
    */
}

ReactDOM.render(
    <Add />,
    document.getElementById('react_add')
);
