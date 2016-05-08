var HelloMessage = React.createClass({
    render() {
        return <h1>Hello {this.props.name}</h1>;
    }
});
ReactDOM.render(
    <HelloMessage name="React" />,
    document.getElementById('react')
);
