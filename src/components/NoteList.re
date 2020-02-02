[@react.component]
let make = () => {
  let dispatch = State.AppStore.useDispatch();
  let notes = State.AppStore.useSelector(Selectors.getNotes);
  let noteList =
    List.map(
      (note: Note.note) => <p> {ReasonReact.string(note.title)} </p>,
      notes,
    );

  <div>
    {ReasonReact.array(Array.of_list(noteList))}
    <button onClick={_ => dispatch(State.ToggleNoteEditor(true))}>
      {ReasonReact.string("New Note")}
    </button>
  </div>;
};
