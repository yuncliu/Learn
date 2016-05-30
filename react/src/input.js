class Hello extends React.Component {
    handleClick(ev) {
        console.log("hellow")
    }
    render() {
        return (
                <div>
                <input type="text" ref = "myTextInput" />
                <input type="button" value="hellow" onClick={ev=>this.handleClick(ev)} />
                </div>
        );
    }
}

ReactDOM.render(
    <Hello />,
    document.getElementById('react_input')
);
