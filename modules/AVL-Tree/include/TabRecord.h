// Copyright 2023 Ermolaev Danila

#pragma once
template <typename TData, typename TKey>
class TabRecord {
 public:
  TKey key;
  TData* data;

  TabRecord(TKey k = {}, TData d = {}) {
    key = k;
    data = new TData(d);
  }
  TabRecord(const TabRecord& T1) {
    key = T1.key;
    data = new TData(*(T1.data));
  }
  ~TabRecord() { delete data; }
  TData* GetData() const { return data; }
  TKey GetKey() const { return key; }
  void SetKey(TKey k) { key = k; }
  void SetData(TData* d) {
    delete data;
    data = d;
  }
  TabRecord<TData, TKey>& operator=(const TabRecord<TData, TKey>& TabR) {
    data = new TData(*(TabR.data));
    key = TabR.key;
    return *this;
  }
};

