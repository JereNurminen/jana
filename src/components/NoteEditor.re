let onEdit = (e: ReactEvent.Form.t) => Js.log(Util.getEventValue(e));

[@react.component]
let make = () => {
  let dispatch = State.AppStore.useDispatch();
  let isOpen = State.AppStore.useSelector(Selectors.isNoteEditorOpen);

  switch (isOpen) {
    | false => ReasonReact.null
    | true => (
        <div>
          <input type_="text" onChange=(onEdit)/>
          <button>
            (ReasonReact.string("save"))
          </button>
        </div>
      )
  };
}
