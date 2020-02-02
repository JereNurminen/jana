open Note

type dataState = {
  notes: list(note)
}

type noteEditorState = {
  isOpen: bool,
  openNoteId: option(int),
  currentNote: option(note)
}

type uiState = {
  noteEditor: noteEditorState
}

type appState = {
  data: dataState,
  ui: uiState
};

type appAction =
  | CreateNote(note)
  | ToggleNoteEditor(bool);

let initialState: appState = {
  data: {
    notes: []
  },
  ui: {
    noteEditor: {
      openNoteId: None,
      currentNote: None,
      isOpen: false
    }
  }
}
 
let reducer = (state, action) =>
  switch action {
  | CreateNote(action) => {...state, data: {...state.data, notes: state.data.notes @ [action]}}
  | ToggleNoteEditor(action) => {...state, ui: {...state.ui, noteEditor: {...state.ui.noteEditor, isOpen: action}}}
  };

let store = Reductive.Store.create(~reducer=reducer, ~preloadedState=initialState, ());

module AppStore = {
  include ReductiveContext.Make({
    type action = appAction;
    type state = appState;
  });
};
