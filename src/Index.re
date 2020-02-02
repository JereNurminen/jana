ReactDOMRe.renderToElementWithId(
  <State.AppStore.Provider store=State.store>
    <NoteList />
    <NoteEditor />
  </State.AppStore.Provider>,
  "content",
);
