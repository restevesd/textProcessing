tr -c -d [[:alpha:][:space:]] | tr -s [:space:] | tr [:upper:] [:lower:] | sed 's/^ *//'
