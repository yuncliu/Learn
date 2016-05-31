let data = [
  {id: 1, author: "Pete Hunt", text: "This is one comment"},
  {id: 2, author: "Jordan Walke", text: "This is *another* comment"}
];

class CommentBox extends React.Component {
    render() {
        return (<div className="CommentBox">
                This is a CommentBox
                <CommentList data={this.props.data} />
                <CommentForm />
                </div>);
    }
}

class CommentList extends React.Component {
    render() {
		let commentNodes = this.props.data.map(comment=> {
            console.log(comment.author);
            return (<Comment author={comment.author}>{comment.text}</Comment>);
        });
        return (<div className="CommentList">
                {commentNodes}
                </div>);
    }
}

class CommentForm extends React.Component {
    render() {
        return (<div className="CommentForm">This is a CommentForm</div>);
    }
}

class Comment extends React.Component {
    render() {
        return (<div className="Comment">
                <h2>{this.props.author}</h2>
                {this.props.children}
                </div>);
    }
}

ReactDOM.render(
    <CommentBox data={data}/>,
    document.getElementById("app")
);
