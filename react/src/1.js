let names = ['aa','bb','cc'];
class Hello extends React.Component {
    render() {
        return (
                <ul>
                {
                    React.Children.map(names, function(name){
                        return <li><button>{name}</button></li>;
                    })
                }
                </ul>
       );
    }
}

ReactDOM.render(
    <Hello name="React" />,
    document.getElementById('react')
);
