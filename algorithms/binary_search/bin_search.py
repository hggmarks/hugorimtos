from typing import Union

def bin_search(sorted_list: list, term: Union[str, int], low: int, high: int, index_offset: int = 0) -> Union[tuple, int]:

    if low <= high:
        mid = (low + high) // 2
        
        if term == sorted_list[mid]:
            return mid+index_offset, sorted_list[mid]
        
        elif term > sorted_list[mid]:
            return bin_search(sorted_list, term, mid+1, high, index_offset)
        
            
        return bin_search(sorted_list, term, low, mid-1, index_offset)
        
    else:
        return -1

