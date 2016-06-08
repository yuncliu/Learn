class Hello extends React.Component {
    constructor() {
        super()
        this.state = {value:'xxx'}
        this.handleChange = this.handleChange.bind(this)
        this.handleClick = this.handleClick.bind(this)
    }
    render() {
        return (<div>
                <p><input type="text" className="form-control"
                    value={this.state.value}
                    onChange={this.handleChange}></input></p>
                <p><input type="button" className="btn btn-primary"
                    value="hellow"
                    onClick={this.handleClick}></input></p>
                </div>
                );
    }
    handleClick(ev) {
        console.log(this.state.value)
    }

    handleChange(ev) {
        this.setState({value: ev.target.value});
    }
}

ReactDOM.render(
    <Hello name="React" />,
    document.getElementById('react')
);
