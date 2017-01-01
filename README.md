# Scripts for generating grams from large datasets

## Dowloading texts

```
make get_data
```

## Cleaning data

```
make clean_txt_files
```

## Create 1,2 grams:

```
make compile
make run
```

Grams are created as `data/gram*.csv`

## Prepare data for prediction

```
make prepare_data_simple_prediction:
```

## Calulace accuracy

```
make generate_tests
make accuracy
```

