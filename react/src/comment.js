class Comment extends React.Component {
    constructor() {
        super()
        this.state = {list: [], text:''}
        $.ajax({
            url: '/api/list',
            success : (data)=>{
                console.log(data)
                this.setState({list:data})
            }
        })
        this.handleSubmit = this.handleSubmit.bind(this)
        this.handleTextChange = this.handleTextChange.bind(this)
    }

    render() {
        return (<div>
                <ul>{
                this.state.list.map(function(name, idx){
                    return <li key={idx}>{name}</li>
                })
                }</ul>
                <textarea value={this.state.text}
                    onChange={this.handleTextChange}></textarea>
                <p><input type="button" value="Submit"
                   onClick={this.handleSubmit}></input></p>
                </div>);
    }

    handleSubmit(ev) {
        $.ajax({
            url: '/api/submit_comment',
            method: 'POST',
            contentType : 'application/json',
            data: JSON.stringify({"key": this.state.text}),
            success : (data) =>{
                console.log(data)
                this.setState({list:data})
            }
        })
    }
    handleTextChange(ev) {
        this.setState({text:ev.target.value})
    }
}

ReactDOM.render(
    <Comment />,
    document.getElementById('app')
);
