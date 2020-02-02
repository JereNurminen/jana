type fieldTypes =
  | ShortText
  | LongText
  | Number(float)
  | Slider(int, int);

type field = {
  name: string,
  fieldType: fieldTypes,
  value: string,
};

type note = {
  title: string,
  fields: option(list(field)),
};
