const s = {
    color:'green',
    width:'100px'
}

class Hello extends React.Component {
    constructor() {
        super()
        this.state = {value:'xxx'}
        this.handleChange = this.handleChange.bind(this)
        this.handleClick = this.handleClick.bind(this)
    }
    render() {
        return (<div>
                <p><input style={s} type="text" value={this.state.value}
                    onChange={this.handleChange}></input></p>
                <p><input type="button" className="btn-lg" value="hellow" onClick={this.handleClick}></input></p>
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
